import json

def evaluate_deployments(deployments):
    success_count = 0
    fail_count = 0
    error_count = 0

    for deployment in deployments:
        try:
            data = json.loads(deployment)

            # Validate deployment_id
            if ("deployment_id" not in data or "status" not in data or 
                not isinstance(data["deployment_id"], str) or 
                not data["deployment_id"].startswith("d-") or 
                len(data["deployment_id"]) != 12 or 
                not data["deployment_id"][2:].isalnum()):
                error_count += 1
                continue

            # Validate status
            if data["status"] == "Success":
                success_count += 1
            elif data["status"] == "Fail":
                fail_count += 1
            else:
                error_count += 1  # Invalid status

        except (json.JSONDecodeError, KeyError, TypeError):
            error_count += 1  # JSON parsing error or missing keys

    print(success_count)
    print(fail_count)
    print(error_count)

# Example test case
deployments = [
    '{"deployment_id": "d-12345678ab", "status": "Success"}',
    '{"deployment_id": "d-09876543cd", "status": "Fail"}'
]

evaluate_deployments(deployments)
