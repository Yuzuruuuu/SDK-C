import argparse
import json
import os
import re

def main():
    script_path = os.path.dirname(os.path.realpath(__file__))

    # Parse arguments
    parser = argparse.ArgumentParser(description='Generate a dictionary for i18n')
    parser.add_argument('lang', type=str, help='Language code')
    args = parser.parse_args()

    entries = []

    # Load existing dictionary if exists
    if os.path.exists(os.path.join(script_path, '..', 'i18n', args.lang + '.json')):
        with open(os.path.join(script_path, '..', 'i18n', args.lang + '.json'), 'r', encoding='utf-8') as f:
            entries = json.load(f)

    # Extract all possible entries
    for file in os.listdir(os.path.join(script_path, '..', 'include')):
        if not file.endswith('.h'):
            continue

        with open(os.path.join(script_path, '..', 'include', file), 'r', encoding='utf-8') as f:
            regex = re.compile(r'^ *\/\/\/ (@brief|@param \S+|@return) (.*)$')
            for line in f:
                match = regex.match(line)
                if not match:
                    continue

                found = False
                for entry in entries:
                    if entry['key'] == match.group(2) and entry['type'] == match.group(1):
                        found = True
                        break
                
                if found:
                    continue

                entries.append({
                    'key': match.group(2),
                    'type': match.group(1),
                    args.lang: '<no translation>'
                })

    # Write a JSON file
    with open(os.path.join(script_path, '..', 'i18n', args.lang + '.json'), 'w', encoding='utf-8') as f:
        json.dump(entries, f, indent=4, ensure_ascii=False)

if __name__ == '__main__':
    main()